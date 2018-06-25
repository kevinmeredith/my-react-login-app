/* State declaration */
type state = {
  remainingAttempts: option (int)
};

type t = A of int | B of float | C of string

/* Action declaration */
type action =
  | ProceedToApp /* Succesfully logged into app. */
  | CommentOnRemainingAttempts int
  | InformUserIsLockedOut;  /* Server notes that user's account is in a bad state such that he/she must be kicked out. */

/* Component template declaration.
   Needs to be **after** state and action declarations! */
let component = ReasonReact.reducerComponent("Login");

/* greeting and children are props. `children` isn't used, therefore ignored.
   We ignore it by prepending it with an underscore */
let make = (~greeting, _children) => {
  /* spread the other default fields of component here and override a few */
  ...component,

  initialState: () => {count: 0, show: true},

  /* State transitions */
  reducer: (action, state) =>
    switch (action) {
    | ProceedToApp => ???
    | CommentOnRemainingAttempts numberLeft => ReasonReact.Update({...state, remainingAttempts: Some numberLeft})
    },

  render: self => {
    let message =
      "You've clicked this " ++ string_of_int(self.state.count) ++ " times(s)";
    <div>
      <button onClick=(_event => self.send(Click))>
        (ReasonReact.string(message))
      </button>
      <button onClick=(_event => self.send(Toggle))>
        (ReasonReact.string("Toggle greeting"))
      </button>
      (self.state.show ? ReasonReact.string(greeting) : ReasonReact.null)
    </div>;
  },
};


/*let make = (~message, _children) => {*/
  /*...component,*/
  /*render: self =>*/
       /*<form>*/
        /*<label for="username">Username</label>*/
        /*<input type="text" name="Username" id="username">*/
        /*<label for="password">Password</label>*/
        /*<input type="password" name="Password" id="password"    >*/
       /*</form>*/

   /*<div onClick=(self.handle(handleClick))> (ReasonReact.string(message)) </div>,*/
/*};*/
