/* This is the basic component. */
let component = ReasonReact.statelessComponent("Login");

let handleClick = (_event, _self) => Js.log("clicked!");
 
/* `make` is the function that mandatorily takes `children` (if you want to use
   `JSX). `message` is a named argument, which simulates ReactJS props. Usage:

   `<Page message="hello" />`

   Which desugars to

   `ReasonReact.element(Page.make(~message="hello", [||]))`*/
let make = (~message, _children) => {
  ...component,
  render: self =>
    <div>
      <span>(ReasonReact.string("Login"))</span>
      <input type_="text"/>
      <input type_="password"/>
      <button onClick=(_event => self.send(Toggle))>
        (ReasonReact.string("Submit"))
      </button>    
    </div>
};
