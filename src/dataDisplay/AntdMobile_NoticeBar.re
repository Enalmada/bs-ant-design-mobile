[@bs.module] external reactClass: ReasonReact.reactClass = "antd-mobile/lib/notice-bar";

/*
 [%bs.raw {|require("antd-mobile/lib/card/style")|}];
 */

/* 2.2.5
   mode	Type of NoticeBar, options: closable link	String	''
   icon	Set the icon at the start position	ReactNode	<Icon type={require('./trips.svg')} size="xxs" />
   onClick	A callback function, can be executed when you close the notice or click on the operating area	(): void
   marqueeProps	marquee params	Object	{loop: false, leading: 500, trailing: 800, fps: 40, style: {}}
   action	text which is used to replace icon	ReactElement
          */

[@bs.deriving abstract]
type marqueeProps = {
  loop: bool,
  leading: int,
  trailing: int,
  fps: int,
  style: ReactDOMRe.Style.t,
};

[@bs.deriving jsConverter]
type mode = [ | `closable | `link];

[@bs.obj]
external makeProps:
  (
    ~mode: string=?,
    ~icon: ReasonReact.reactElement=?,
    ~onClick: unit => unit=?,
    ~marqueeProps: marqueeProps=?,
    ~action: ReasonReact.reactElement=?,
    ~id: string=?,
    ~className: string=?,
    ~style: ReactDOMRe.Style.t=?,
    unit
  ) =>
  _ =
  "";

let make = (~mode=?, ~icon=?, ~onClick=?, ~marqueeProps=?, ~action=?, ~id=?, ~className=?, ~style=?, children) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      makeProps(
        ~mode=?Js.Option.map((. b) => modeToJs(b), mode),
        ~icon?,
        ~onClick?,
        ~marqueeProps?,
        ~action?,
        ~id?,
        ~className?,
        ~style?,
        (),
      ),
    children,
  );
