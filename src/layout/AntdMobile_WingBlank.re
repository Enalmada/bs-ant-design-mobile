[@bs.module] external reactClass: ReasonReact.reactClass = "antd-mobile/lib/wing-blank";

/*
 [%bs.raw {|require("antd-mobile/lib/wing-blank/style")|}];
 */

[@bs.deriving jsConverter]
type buttonSize = [ | `sm | `md | `lg];

/* 2.2.5
   size	left and right blank space, optional values:sm,md,lg	string	lg
    */

[@bs.obj]
external makeProps: (~size: string=?, ~id: string=?, ~className: string=?, ~style: ReactDOMRe.Style.t=?, unit) => _ =
  "";

let make = (~size=?, ~id=?, ~className=?, ~style=?, children) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=makeProps(~size=?Js.Option.map((. b) => buttonSizeToJs(b), size), ~id?, ~className?, ~style?, ()),
    children,
  );
