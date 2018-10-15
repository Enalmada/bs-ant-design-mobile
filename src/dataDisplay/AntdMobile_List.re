[@bs.module] external reactClass: ReasonReact.reactClass = "antd-mobile/lib/list";

/*
 [%bs.raw {|require("antd-mobile/lib/list/style")|}];
 */

/*
 renderHeader	list heder	(): void
 renderFooter	list footer	(): void
    */

[@bs.obj]
external makeProps:
  (
    ~renderHeader: string=?,
    ~renderFooter: string=?,
    ~id: string=?,
    ~className: string=?,
    ~style: ReactDOMRe.Style.t=?,
    unit
  ) =>
  _ =
  "";

let make = (~renderHeader=?, ~renderFooter=?, ~id=?, ~className=?, ~style=?, children) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=makeProps(~renderHeader?, ~renderFooter?, ~id?, ~className?, ~style?, ()),
    children,
  );

module Item = {
  [@bs.module "antd-mobile/lib/list"] external item: ReasonReact.reactClass = "Item";

  [@bs.deriving jsConverter]
  type arrow = [ | `horizontal | `up | `down | `empty];

  [@bs.deriving jsConverter]
  type align = [ | `top | `middle | `bottom];

  [@bs.deriving jsConverter]
  type platform = [ | `android | `ios | `cross];

  /* 2.2.5
     thumb	thumbnail on the left side of List(string type will be used to set img src)	String/React.Element
     extra	extra content on the right side of List	String/React.Element
     arrow	arrow direction, options: horizontal,up,down, empty; empty option may hide the dom	String
     align	vertical alignment of child elements?options: top,middle,bottom	String	middle
     onClick	callback is called when list is clicked	(): void
     error	Whether to display error style(the color of text on the right side may change to orange)	Boolean	false
     multipleLine	multiple line	Boolean	false
     wrap	Whether to wrap long texts, otherwise it will be hidden by default.	Boolean	false
     activeStyle	customized active style	Object
     platform	set the special style depends on platform, Options android, ios? default to be cross? which means we will detect UA and change the component style	String	'cross'
     */

  [@bs.obj]
  external makeProps:
    (
      ~thumb: string=?,
      ~extra: ReasonReact.reactElement=?,
      ~arrow: string=?,
      ~align: string=?,
      ~onClick: ReactEvent.Mouse.t => unit=?,
      ~error: bool=?,
      ~multipleLine: bool=?,
      ~wrap: bool=?,
      ~activeStyle: ReactDOMRe.Style.t=?,
      ~platform: string=?,
      ~disabled: bool=?,
      ~id: string=?,
      ~className: string=?,
      ~style: ReactDOMRe.Style.t=?,
      unit
    ) =>
    _ =
    "";
  let make =
      (
        ~thumb=?,
        ~extra=?,
        ~arrow=?,
        ~align=?,
        ~onClick=?,
        ~error=?,
        ~multipleLine=?,
        ~wrap=?,
        ~activeStyle=?,
        ~platform=?,
        ~disabled=?,
        ~id=?,
        ~className=?,
        ~style=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=item,
      ~props=
        makeProps(
          ~thumb?,
          ~extra?,
          ~arrow=?Js.Option.map((. b) => arrowToJs(b), arrow),
          ~align=?Js.Option.map((. b) => alignToJs(b), align),
          ~onClick?,
          ~error?,
          ~multipleLine?,
          ~wrap?,
          ~activeStyle?,
          ~platform=?Js.Option.map((. b) => platformToJs(b), platform),
          ~disabled?,
          ~id?,
          ~className?,
          ~style?,
          (),
        ),
      children,
    );

  module Brief = {
    [@bs.module "antd-mobile/lib/list/ListItem"] external brief: ReasonReact.reactClass = "Brief";

    [@bs.obj] external makeProps: (~id: string=?, ~className: string=?, ~style: ReactDOMRe.Style.t=?, unit) => _ = "";
    let make = (~id=?, ~className=?, ~style=?, children) =>
      ReasonReact.wrapJsForReason(~reactClass=brief, ~props=makeProps(~id?, ~className?, ~style?, ()), children);
  };
};
