[@bs.module] external reactClass: ReasonReact.reactClass = "antd-mobile/lib/icon";

/*
 [%bs.raw {|require("antd-mobile/lib/icon/style")|}];
 */

[@bs.deriving jsConverter]
type size = [ | `xxs | `xs | `sm | `md | `lg];

[@bs.deriving jsConverter]
type typeIcon = [
  | [@bs.as "check-circle"] `checkCircle
  | `check
  | [@bs.as "check-circle-o"] `checkCircleO
  | [@bs.as "cross-circle"] `crossCircle
  | `cross
  | [@bs.as "cross-circle-o"] `crossCircleO
  | `up
  | `left
  | `right
  | `ellipsis
  | `loading
  | `search
];

/* 2.2.5
   type	string name of built-in icon	String
   size	icon size	'xxs'/'xs'/'sm'/'md'/'lg'	md
   color	icon color	Color	'#000'
       */

[@bs.obj]
external makeProps:
  (
    ~_type: string=?,
    ~size: string=?,
    ~color: string=?,
    ~id: string=?,
    ~className: string=?,
    ~style: ReactDOMRe.Style.t=?,
    unit
  ) =>
  _ =
  "";

let make = (~_type=?, ~size=?, ~color=?, ~id=?, ~className=?, ~style=?, children) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      makeProps(
        ~_type=?Js.Option.map((. b) => typeIconToJs(b), _type),
        ~size=?Js.Option.map((. b) => sizeToJs(b), size),
        ~color?,
        ~id?,
        ~className?,
        ~style?,
        (),
      ),
    children,
  );

/*
 let component = ReasonReact.statelessComponent("Icon");
 /* am-icon am-icon-check-circle am-icon-md */
 let make = (~type_=?, ~className=?, ~title=?, ~onClick=?, ~spin=?, ~style=?, _children) => {
   ...component,
   render: _ => <svg className="am-icon am-icon-ellipsis am-icon-md"> <use href="#ellipsis" /> </svg>,
 };

 */
