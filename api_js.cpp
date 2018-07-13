//
// Created by b1u3dr4g0nf1y on 7/13/18.
//

#include "api_js.h"


namespace api {

    using v8::Context;
    using v8::Function;
    using v8::FunctionCallbackInfo;
    using v8::FunctionTemplate;
    using v8::Isolate;
    using v8::Local;
    using v8::Number;
    using v8::Object;
    using v8::Persistent;
    using v8::String;
    using v8::Value;

    Persistent<Function> ManagerWrapper::constructor;

    ManagerWrapper::ManagerWrapper() {

    }

    ManagerWrapper::~ManagerWrapper() {
    }

    void ManagerWrapper::Init(Local<v8::Object> exports) {
        Isolate* isolate = exports->GetIsolate();

        // Prepare constructor template
        Local<FunctionTemplate> tpl = FunctionTemplate::New(isolate, New);
        tpl->SetClassName(String::NewFromUtf8(isolate, "ManagerWrapper"));
        tpl->InstanceTemplate()->SetInternalFieldCount(1);

        // Prototype
        NODE_SET_PROTOTYPE_METHOD(tpl, "getMethod", SimpleGetMethod);
        NODE_SET_PROTOTYPE_METHOD(tpl, "post", SimplePostMethod);

        constructor.Reset(isolate, tpl->GetFunction());
        exports->Set(String::NewFromUtf8(isolate, "ManagerWrapper"),
                     tpl->GetFunction());
    }

    void ManagerWrapper::New(const FunctionCallbackInfo<Value>& args) {
        Isolate* isolate = args.GetIsolate();

        if (args.IsConstructCall()) {
            // Invoked as constructor: `new MyObject(...)`
            ManagerWrapper* obj = new ManagerWrapper();
            obj->Wrap(args.This());
            args.GetReturnValue().Set(args.This());
        } else {
            // Invoked as plain function `MyObject(...)`, turn into construct call.
            const int argc = 1;
            Local<Value> argv[argc] = { args[0] };
            Local<Context> context = isolate->GetCurrentContext();
            Local<Function> cons = Local<Function>::New(isolate, constructor);
            Local<Object> result =
                    cons->NewInstance(context, argc, argv).ToLocalChecked();
            args.GetReturnValue().Set(result);
        }
    }

    void ManagerWrapper::SimpleGetMethod(const FunctionCallbackInfo<Value>& args) {
        Isolate* isolate = args.GetIsolate();

        ManagerWrapper* obj = ObjectWrap::Unwrap<ManagerWrapper>(args.Holder());
        obj->manager.Test();

        args.GetReturnValue().Set(String::NewFromUtf8(isolate, "no Error"));
    }


    void ManagerWrapper::SimplePostMethod(const FunctionCallbackInfo<Value>& args) {
        Isolate* isolate = args.GetIsolate();

        ManagerWrapper* obj = ObjectWrap::Unwrap<ManagerWrapper>(args.Holder());

        //args.GetReturnValue().Set(Number::New(isolate, obj->value_));
    }


}  // namespace demo