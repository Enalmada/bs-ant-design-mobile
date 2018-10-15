[@bs.module] external reactClass: ReasonReact.reactClass = "antd-mobile/lib/popover";

/*
 [%bs.raw {|require("antd-mobile/lib/popover/style")|}];
 */

/*
   align={{
                                    overflow: { adjustY: 0, adjustX: 0 },
                                    offset: [-10, 0],
                                  }}
 */
[@bs.deriving abstract]
type overflow = {
  .
  "adjustY": int,
  "adjustX": int,
};

[@bs.deriving abstract]
type alignConfig = {
  .
  "overflow": overflow,
  "offset": array(int),
};

/* 2.2.5
   visible	visible state	Boolean	false
   onVisibleChange	visible state change callback	(visible: bool): void	-
   placement	enum{'left','right','top','bottom', 'topLeft', 'topRight', 'bottomLeft', 'bottomRight'}	String	'bottomRight'
   mask	Whether to display the mask background layer	Boolean	false
   overlay	Popup layer content	ReactNode	-
   onSelect	when an option is selected	(node: any, index?: number): void	-
        */

/*
 MORE FROM rc-tooltip
 ---------------------------------------------------------------------------
 overlayClassName	string		additional className added to popup overlay
 overlayStyle	Object		additional style of overlay node
 prefixCls	String	rmc-tooltip	prefix class name
 transitionName	String		same as https://github.com/react-component/css-transition-group
 onVisibleChange	Function		call when visible is changed
 afterVisibleChange	Function		call after visible is changed
 visible	boolean		whether tooltip is visible
 defaultVisible	boolean		whether tooltip is visible initially
 placement	String		one of ['left','right','top','bottom', 'topLeft', 'topRight', 'bottomLeft', 'bottomRight']
 align	Object: alignConfig of [dom-align](https://github.com/yiminghe/dom-align)		value will be merged into placement's config
 onPopupAlign	function(popupDomNode, align)		callback when popup node is aligned
 overlay	React.Element | () => React.Element		popup content
 arrowContent	React.Node	null	arrow content
 getTooltipContainer	function		Function returning html node which will act as tooltip container. By default the tooltip attaches to the body. If you want to change the container, simply return a new element.
 destroyTooltipOnHide	boolean	false	whether destroy tooltip when tooltip is hidden
 */

[@bs.deriving jsConverter]
type placement = [ | `left | `right | `top | `bottom | `topLeft | `topRight | `bottomLeft | `bottomRight];

[@bs.obj]
external makeProps:
  (
    ~visible: bool=?,
    ~onVisibleChange: bool => unit=?,
    ~placement: string=?,
    ~mask: bool=?,
    ~overlay: array(ReasonReact.reactElement)=?,
    ~onSelect: int => unit=?,
    ~overlayClassName: string=?,
    ~overlayStyle: ReactDOMRe.Style.t=?,
    ~align: alignConfig=?,
    ~id: string=?,
    ~className: string=?,
    ~style: ReactDOMRe.Style.t=?,
    unit
  ) =>
  _ =
  "";

let make =
    (
      ~visible=?,
      ~onVisibleChange=?,
      ~placement=?,
      ~mask=?,
      ~overlay=?,
      ~onSelect=?,
      ~overlayClassName=?,
      ~overlayStyle=?,
      ~align=?,
      ~id=?,
      ~className=?,
      ~style=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      makeProps(
        ~visible?,
        ~onVisibleChange?,
        ~placement=?Js.Option.map((. b) => placementToJs(b), placement),
        ~mask?,
        ~overlay=?Js.Option.map((. b) => Array.of_list(b), overlay),
        ~onSelect?,
        ~overlayClassName?,
        ~overlayStyle?,
        ~align?,
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
