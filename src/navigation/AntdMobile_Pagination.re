[@bs.module] external reactClass: ReasonReact.reactClass = "antd-mobile/lib/pagination";

/*
 [%bs.raw {|require("antd-mobile/lib/popover/style")|}];
 */

[@bs.deriving abstract]
type locale = {
  .
  "prevText": ReasonReact.reactElement,
  "nextText": ReasonReact.reactElement,
};

/* 2.2.5
   mode	the mode of Pagination which can be one of button,number,pointer	string	button
   current	current page index	number	1
   total	total number of data	number	0
   simple	whether to hide number	boolean	false
   disabled	whether is disabled	boolean	false
   locale	i18n setting, you can override the configuration of the global `LocaleProvider | Object?{prevText, nextText}
   onChange	invoked with the new index when the value changes.	(index: Number): void
         */

[@bs.deriving jsConverter]
type mode = [ | `button | `number | `pointer];

[@bs.obj]
external makeProps:
  (
    ~mode: string=?,
    ~current: int=?,
    ~total: int=?,
    ~simple: bool=?,
    ~disabled: bool=?,
    ~locale: locale=?,
    ~onChange: int => unit=?,
    ~id: string=?,
    ~className: string=?,
    ~style: ReactDOMRe.Style.t=?,
    unit
  ) =>
  _ =
  "";

let make =
    (
      ~mode=?,
      ~current=?,
      ~total=?,
      ~simple=?,
      ~disabled=?,
      ~locale=?,
      ~onChange=?,
      ~id=?,
      ~className=?,
      ~style=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      makeProps(
        ~mode=?Js.Option.map((. b) => modeToJs(b), mode),
        ~current?,
        ~total?,
        ~simple?,
        ~disabled?,
        ~locale?,
        ~onChange?,
        ~id?,
        ~className?,
        ~style?,
        (),
      ),
    children,
  );

/*
 disabled	set disabled	Boolean	false
 style	item style	Object	-
 icon	icon	ReactNode	-
       */

module Item = {
  [@bs.module "antd-mobile/lib/popover"] external item: ReasonReact.reactClass = "Item";
  [@bs.obj]
  external makeProps:
    (
      ~key: string=?,
      ~disabled: bool=?,
      ~icon: ReasonReact.reactElement=?,
      ~value: string=?,
      ~id: string=?,
      ~className: string=?,
      ~style: ReactDOMRe.Style.t=?,
      unit
    ) =>
    _ =
    "";
  let make = (~key_=?, ~disabled=?, ~icon=?, ~value=?, ~id=?, ~className=?, ~style=?, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=item,
      ~props=makeProps(~key=?key_, ~disabled?, ~icon?, ~value?, ~id?, ~className?, ~style?, ()),
      children,
    );
};
