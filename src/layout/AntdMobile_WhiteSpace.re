[@bs.module] external reactClass: ReasonReact.reactClass = "antd-mobile/lib/white-space";

/*
 [%bs.raw {|require("antd-mobile/lib/white-space/style")|}];
 */

[@bs.deriving jsConverter]
type size = [ | `xs | `sm | `md | `lg | `xl];

/* 2.2.5
   size	up and down margins, optional values:xs,sm,md,lg,xl	string	md
    */

[@bs.obj]
external makeProps: (~size: string=?, ~id: string=?, ~className: string=?, ~style: ReactDOMRe.Style.t=?, unit) => _ =
  "";

let make = (~size=?, ~id=?, ~className=?, ~style=?, children) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=makeProps(~size=?Js.Option.map((. b) => sizeToJs(b), size), ~id?, ~className?, ~style?, ()),
    children,
  );
