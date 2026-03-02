/**
 * @return {Function}
 */
var createHelloWorld = function() {
    const greet = "Hello World";
    return function(...args) {
        return greet;
    }
};