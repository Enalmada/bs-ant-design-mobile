[@bs.module] external reactClass: ReasonReact.reactClass = "antd-mobile/lib/menu";

/*
 [%bs.raw {|require("antd-mobile/lib/menu/style")|}];
 */

[@bs.deriving jsConverter]
type position = [ | `left | `right | `top | `bottom];

/* 2.2.5
   data	Menu data (children will be ignored when isLeaf is true).	Array<{label: ReactNode, value, disabled?, children<data>?, isLeaf?}>	[]
   level	Menu levels, available values: 1, 2.	number	2
   value	Selected value of Menu, it's a array which includes first and second level's value. When menu is in multiple select mode, if level is 1, all values of array mean multiple select options; if level is 2, the first value of array means first level's option, second value is an array of submenu values	Array	[]
   onChange	Callback called when menu item is selected.	(item: Object): void
   height	Height of Menu.	number	document.documentElement.clientHeight / 2
   multiSelect	support multiple selection	boolean	false
       */

[@bs.obj]
external makeProps:
  (
    ~data: 'a=?,
    ~level: int=?,
    ~value: array(int)=?,
    ~onChange: unit => unit=?,
    ~height: int=?,
    ~multiSelect: bool=?,
    ~id: string=?,
    ~className: string=?,
    ~style: ReactDOMRe.Style.t=?,
    unit
  ) =>
  _ =
  "";

let make =
    (~data=?, ~level=?, ~value=?, ~onChange=?, ~height=?, ~multiSelect=?, ~id=?, ~className=?, ~style=?, children) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=makeProps(~data?, ~level?, ~value?, ~onChange?, ~height?, ~multiSelect?, ~id?, ~className?, ~style?, ()),
    children,
  );
