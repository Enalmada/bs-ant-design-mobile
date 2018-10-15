[@bs.module] external reactClass: ReasonReact.reactClass = "antd-mobile/lib/card";

/*
 [%bs.raw {|require("antd-mobile/lib/card/style")|}];
 */

/* 2.2.5
   full	whether is full column	boolean	false
       */

[@bs.obj]
external makeProps: (~full: bool=?, ~id: string=?, ~className: string=?, ~style: ReactDOMRe.Style.t=?, unit) => _ = "";

let make = (~full=?, ~id=?, ~className=?, ~style=?, children) =>
  ReasonReact.wrapJsForReason(~reactClass, ~props=makeProps(~full?, ~id?, ~className?, ~style?, ()), children);

module Header = {
  [@bs.module "antd-mobile/lib/card"] external item: ReasonReact.reactClass = "Header";

  /*
   title	title for Card.Header	React.Element?String
   thumb	thumb to render in the left of Card.Header	String?React.Element
   thumbStyle	style of thumb	Object	{}
   extra	extra content to render in the right of Card.Header	React.Element?String
      */

  [@bs.obj]
  external makeProps:
    (
      ~title: ReasonReact.reactElement=?,
      ~thumb: ReasonReact.reactElement=?,
      ~thumbStyle: ReactDOMRe.Style.t=?,
      ~extra: ReasonReact.reactElement=?,
      ~id: string=?,
      ~className: string=?,
      ~style: ReactDOMRe.Style.t=?,
      unit
    ) =>
    _ =
    "";
  let make = (~title=?, ~thumb=?, ~thumbStyle=?, ~extra=?, ~id=?, ~className=?, ~style=?, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=item,
      ~props=makeProps(~title?, ~thumb?, ~thumbStyle?, ~extra?, ~id?, ~className?, ~style?, ()),
      children,
    );
};

module Body = {
  [@bs.module "antd-mobile/lib/card"] external item: ReasonReact.reactClass = "Body";

  [@bs.obj] external makeProps: (~id: string=?, ~className: string=?, ~style: ReactDOMRe.Style.t=?, unit) => _ = "";
  let make = (~id=?, ~className=?, ~style=?, children) =>
    ReasonReact.wrapJsForReason(~reactClass=item, ~props=makeProps(~id?, ~className?, ~style?, ()), children);
};

module Footer = {
  [@bs.module "antd-mobile/lib/card"] external item: ReasonReact.reactClass = "Footer";

  /*
   content	content of Card.Footer	React.Element?String
   extra	extra content of Card.Footer	React.Element?String

   */

  [@bs.obj]
  external makeProps:
    (
      ~content: ReasonReact.reactElement=?,
      ~extra: ReasonReact.reactElement=?,
      ~id: string=?,
      ~className: string=?,
      ~style: ReactDOMRe.Style.t=?,
      unit
    ) =>
    _ =
    "";
  let make = (~content=?, ~extra=?, ~id=?, ~className=?, ~style=?, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=item,
      ~props=makeProps(~content?, ~extra?, ~id?, ~className?, ~style?, ()),
      children,
    );
};
