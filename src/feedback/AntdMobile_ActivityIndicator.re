[@bs.module] external reactClass: ReasonReact.reactClass = "antd-mobile/lib/activity-indicator";

/*
 [%bs.raw {|require("antd-mobile/lib/activity-indicator/style")|}];
 */

/* 2.2.5
   animating	Whether to show the indicator (true, the default) or hide it (false).	boolean	true
   size	Size of the indicator (small/large)	string	small
   toast	Whether to use toast style	boolean	false
   text	loading text behind the indicator	string	-
             */

[@bs.deriving jsConverter]
type size = [ | `small | `large];

[@bs.obj]
external makeProps:
  (
    ~animating: bool=?,
    ~size: string=?,
    ~toast: bool=?,
    ~text: string=?,
    ~id: string=?,
    ~className: string=?,
    ~style: ReactDOMRe.Style.t=?,
    unit
  ) =>
  _ =
  "";

let make = (~animating=?, ~size=?, ~toast=?, ~text=?, ~id=?, ~className=?, ~style=?, children) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      makeProps(
        ~animating?,
        ~size=?Js.Option.map((. b) => sizeToJs(b), size),
        ~toast?,
        ~text?,
        ~id?,
        ~className?,
        ~style?,
        (),
      ),
    children,
  );
