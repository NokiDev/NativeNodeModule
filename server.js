let nativeModule = require('./nativeModule');

console.log(nativeModule);
let manager = new nativeModule.ManagerWrapper();
manager.getMethod();

console.log(world);

