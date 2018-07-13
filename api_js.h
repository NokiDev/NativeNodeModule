//
// Created by b1u3dr4g0nf1y on 7/13/18.
//

#ifndef NATIVENODEMODULE_API_JS_H
#define NATIVENODEMODULE_API_JS_H

#include <node.h>
#include <node_object_wrap.h>

#include "managerImpl.h"


namespace api {

    class ManagerWrapper : public node::ObjectWrap {
    public:
        static void Init(v8::Local<v8::Object> exports);

    private:
        explicit ManagerWrapper();
        ~ManagerWrapper();

        static void New(const v8::FunctionCallbackInfo<v8::Value>& args);
        static void SimpleGetMethod(const v8::FunctionCallbackInfo<v8::Value>& args);
        static void SimplePostMethod(const v8::FunctionCallbackInfo<v8::Value>& args);

        static v8::Persistent<v8::Function> constructor;
        ManagerImpl manager; // Pimpl
    };

}  // namespace demo

#endif //NATIVENODEMODULE_API_JS_H
