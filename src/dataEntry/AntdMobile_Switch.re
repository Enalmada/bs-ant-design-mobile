[@bs.module] external reactClass: ReasonReact.reactClass = "antd-mobile/lib/switch";

/*
 [%bs.raw {|require("antd-mobile/lib/radio/style")|}];
 */

/* 2.2.5
   checked	Whether is checked by default	Boolean	false
   disabled	whether is disabled	Boolean	false
   color	Background color when the switch is turned on.	String	#4dd865
   onChange	The callback function that is triggered when the selected state changes.	(checked: bool): void	-
   name	name of switch	String
   platform	set the special style depends on platform, Options android, ios? default to be ios	String	'ios'
       */

[@bs.deriving jsConverter]
type platform = [ | `android | `ios];

[@bs.obj]
external makeProps:
  (
    ~checked: bool=?,
    ~disabled: bool=?,
    ~color: string=?,
    ~onChange: bool => unit=?,
    ~onClick: bool => unit=?,
    ~name: string=?,
    ~platform: string=?,
    ~id: string=?,
    ~className: string=?,
    ~style: ReactDOMRe.Style.t=?,
    unit
  ) =>
  _ =
  "";

let make =
    (
      ~checked=?,
      ~disabled=?,
      ~color=?,
      ~onChange=?,
      ~onClick=?,
      ~name=?,
      ~platform=?,
      ~id=?,
      ~className=?,
      ~style=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      makeProps(
        ~checked?,
        ~disabled?,
        ~color?,
        ~onChange?,
        ~onClick?,
        ~name?,
        ~platform=?Js.Option.map((. b) => platformToJs(b), platform),
        ~id?,
        ~className?,
        ~style?,
        (),
      ),
    children,
  );
