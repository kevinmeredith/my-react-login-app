let component = ReasonReact.statelessComponent("Login");

let handleClick = (_event, _self) => Js.log("clicked!");

let make = (~username: string, ~password: string, _children) => {
  ...component,
  render: (_) =>
    <div>
      <h1>{ReasonReact.string("Log in")}</h1>
      <div><LoginUsername key=username value=username/></div>
      <div><LoginPassword key=password value=password/></div>
    </div>
};