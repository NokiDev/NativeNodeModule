//
// Created by b1u3dr4g0nf1y on 7/13/18.
//


// hello.cc using N-API
// hello.cc
#include <node.h>

#include "api_js.h"

namespace demo {

    using v8::FunctionCallbackInfo;
    using v8::Isolate;
    using v8::Local;
    using v8::Object;
    using v8::String;
    using v8::Value;


    void InitAll(Local<Object> exports) {
        api::ManagerWrapper::Init(exports);
    }

    NODE_MODULE(NODE_GYP_MODULE_NAME, InitAll)
}  // namespace demo

