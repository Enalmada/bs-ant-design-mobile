[@bs.module "antd-mobile/lib/radio"] external reactClass: ReasonReact.reactClass = "default";

/*
 [%bs.raw {|require("antd-mobile/lib/radio/style")|}];
 */

/* 2.2.5
   name	name	String	-
   defaultChecked	the initial checked state	Boolean	-
   checked	to set the current checked state	Boolean	-
   disabled	whether disabled	Boolean	false
   onChange	a callback function, can be executed when the checked state changes	(e: Object): void	-
      */

[@bs.obj]
external makeProps:
  (
    ~name: string=?,
    ~defaultChecked: bool=?,
    ~checked: bool=?,
    ~disabled: bool=?,
    ~onChange: unit => unit=?,
    ~id: string=?,
    ~className: string=?,
    ~style: ReactDOMRe.Style.t=?,
    unit
  ) =>
  _ =
  "";

let make = (~name=?, ~defaultChecked=?, ~checked=?, ~disabled=?, ~onChange=?, ~id=?, ~className=?, ~style=?, children) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=makeProps(~name?, ~defaultChecked?, ~checked?, ~disabled?, ~onChange?, ~id?, ~className?, ~style?, ()),
    children,
  );

module RadioItem = {
  [@bs.module] external item: ReasonReact.reactClass = "antd-mobile/lib/radio/RadioItem";

  /* 2.2.5

     */

  [@bs.obj]
  external makeProps:
    (
      ~key: string=?,
      ~name: string=?,
      ~defaultChecked: bool=?,
      ~checked: bool=?,
      ~disabled: bool=?,
      ~onChange: unit => unit=?,
      ~id: string=?,
      ~className: string=?,
      ~style: ReactDOMRe.Style.t=?,
      unit
    ) =>
    _ =
    "";
  let make =
      (
        ~key_=?,
        ~name=?,
        ~defaultChecked=?,
        ~checked=?,
        ~disabled=?,
        ~onChange=?,
        ~id=?,
        ~className=?,
        ~style=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=item,
      ~props=
        makeProps(
          ~key=?key_,
          ~name?,
          ~defaultChecked?,
          ~checked?,
          ~disabled?,
          ~onChange?,
          ~id?,
          ~className?,
          ~style?,
          (),
        ),
      children,
    );
};
