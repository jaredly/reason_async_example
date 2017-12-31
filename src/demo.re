Js.log("Hello, BuckleScript and Reason!");

let getThing = () => Js.Promise.make((~resolve, ~reject) => [@bs]resolve(20));

let getOtherThing = () => Js.Promise.make((~resolve, ~reject) => [@bs]resolve(40));

let module Let_syntax = Reason_async.Promise;
let doSomething = () => {
  [%await let x = Js.Promise.resolve(10)

  and y = getThing()];
  /* ... */
  [%awaitWrap let z = getOtherThing()];
  x + y + z + 3
};

/* Heyy look we have top-level await!
 * `consume` means "give me this promise, and have the result
 * of this whole expression be ()" */
{
  [%consume let result = doSomething()];
  Js.log(result)
};