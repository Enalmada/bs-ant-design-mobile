[@bs.module] external reactClass: ReasonReact.reactClass = "antd-mobile/lib/flex";

/*
 [%bs.raw {|require("antd-mobile/lib/white-space/style")|}];
 */

[@bs.deriving jsConverter]
type direction = [ | `row | [@bs.as "row-reverse"] `rowReverse | `column | [@bs.as "column-reverse"] `columnReverse];

[@bs.deriving jsConverter]
type wrap = [ | `nowrap | `wrap | [@bs.as "wrap-reverse"] `wrapReverse];

[@bs.deriving jsConverter]
type justify = [ | `start | [@bs.as "end"] `flexEnd | `center | `between | `around];

[@bs.deriving jsConverter]
type align = [ | `start | `center | [@bs.as "end"] `flexEnd | `baseline | `stretch];

[@bs.deriving jsConverter]
type alignContent = [ | `start | `center | [@bs.as "end"] `flexEnd | `between | `around | `stretch];

/* 2.2.5
   direction	how flex items are placed in the flex container?value could be row,row-reverse,column,column-reverse, RN only support row,column	String	row
   wrap	the wrap way of sub-elements?option nowrap,wrap,wrap-reverse,RN only support nowrap,wrap	String	nowrap
   justify	the way of alignment for sub-elements of main axis, option start,end,center,between,around	String	start
   align	the way of alignment for sub-elements of cross-axis, option start,center,end,baseline,stretch RN only support start,end,center,stretch	String	center
   alignContent	the way of alignment when have multiple axes, option start,end,center,between,around,stretch	String	stretch
     */

[@bs.obj]
external makeProps:
  (
    ~direction: string=?,
    ~wrap: string=?,
    ~justify: string=?,
    ~align: string=?,
    ~alignContent: string=?,
    ~id: string=?,
    ~className: string=?,
    ~style: ReactDOMRe.Style.t=?,
    unit
  ) =>
  _ =
  "";

let make = (~direction=?, ~wrap=?, ~justify=?, ~align=?, ~alignContent=?, ~id=?, ~className=?, ~style=?, children) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      makeProps(
        ~direction=?Js.Option.map((. b) => directionToJs(b), direction),
        ~wrap=?Js.Option.map((. b) => wrapToJs(b), wrap),
        ~justify=?Js.Option.map((. b) => justifyToJs(b), justify),
        ~align=?Js.Option.map((. b) => alignToJs(b), align),
        ~alignContent=?Js.Option.map((. b) => alignContentToJs(b), alignContent),
        ~id?,
        ~className?,
        ~style?,
        (),
      ),
    children,
  );

module Item = {
  [@bs.module "antd-mobile/lib/flex"] external item: ReasonReact.reactClass = "Item";
  [@bs.obj]
  external makeProps: (~key: string=?, ~id: string=?, ~className: string=?, ~style: ReactDOMRe.Style.t=?, unit) => _ =
    "";
  let make = (~key_=?, ~id=?, ~className=?, ~style=?, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=item,
      ~props=makeProps(~key=?key_, ~id?, ~className?, ~style?, ()),
      children,
    );
};
