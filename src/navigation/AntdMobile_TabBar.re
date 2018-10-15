[@bs.module "antd-mobile/lib/tab-bar"] external reactClass: ReasonReact.reactClass = "default";

/*
 [%bs.raw {|require("antd-mobile/lib/tab-bar/style")|}];
 */

/* 2.2.5
   barTintColor	tabbar's background color	String	white
   tintColor	selected's font color	String	#108ee9
   unselectedTintColor	unselected's font color	String	'#888'
   hidden	whether it is hidden	Boolean	false
   prefixCls	prefix className	String	'am-tab-bar'
   noRenderContent	can't render content	Boolean	false
   prerenderingSiblingsNumber	pre-render nearby sibling, Infinity: render all the siblings, 0: render current page	number	1
   tabBarPosition	tabbar position	'top'|'bottom'	'bottom'
           */

[@bs.deriving jsConverter]
type tabBarPosition = [ | `top | `bottom];

[@bs.obj]
external makeProps:
  (
    ~barTintColor: string=?,
    ~tintColor: string=?,
    ~unselectedTintColor: string=?,
    ~hidden: bool=?,
    ~prefixCls: string=?,
    ~noRenderContent: bool=?,
    ~prerenderingSiblingsNumber: int=?,
    ~tabBarPosition: string=?,
    ~id: string=?,
    ~className: string=?,
    ~style: ReactDOMRe.Style.t=?,
    unit
  ) =>
  _ =
  "";

let make =
    (
      ~barTintColor=?,
      ~tintColor=?,
      ~unselectedTintColor=?,
      ~hidden=?,
      ~prefixCls=?,
      ~noRenderContent=?,
      ~prerenderingSiblingsNumber=?,
      ~tabBarPosition=?,
      ~id=?,
      ~className=?,
      ~style=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      makeProps(
        ~barTintColor?,
        ~tintColor?,
        ~unselectedTintColor?,
        ~hidden?,
        ~prefixCls?,
        ~noRenderContent?,
        ~prerenderingSiblingsNumber?,
        ~tabBarPosition=?Js.Option.map((. b) => tabBarPositionToJs(b), tabBarPosition),
        ~id?,
        ~className?,
        ~style?,
        (),
      ),
    children,
  );

/*
 badge	badge number	Number \ String	?
 dot	show red dot on right-top?invalid when set badge number?	Boolean	false
 onPress	on press the bar, need change component by yourself. state & selecte={true}	Function	(){}
 selected	whether it is selected	Boolean	false
 icon	the default icon	ref demo
 selectedIcon	the icon of selected	ref demo
 title	title	String
 key	unique identification	String	?
 */

module Item = {
  [@bs.module "antd-mobile/lib/tab-bar"] external item: ReasonReact.reactClass = "Item";
  /* [@bs.module] external item: ReasonReact.reactClass = "antd-mobile/lib/tab-bar"; */

  [@bs.obj]
  external makeProps:
    (
      ~badge: string=?,
      ~dot: bool=?,
      ~onPress: unit => unit=?,
      ~selected: bool=?,
      ~icon: ReasonReact.reactElement=?,
      ~selectedIcon: ReasonReact.reactElement=?,
      ~title: string=?,
      ~key: string=?,
      ~id: string=?,
      ~className: string=?,
      ~style: ReactDOMRe.Style.t=?,
      unit
    ) =>
    _ =
    "";
  let make =
      (
        ~badge=?,
        ~dot=?,
        ~onPress=?,
        ~selected=?,
        ~icon=?,
        ~selectedIcon=?,
        ~title=?,
        ~key_=?,
        ~id=?,
        ~className=?,
        ~style=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=item,
      ~props=
        makeProps(
          ~badge?,
          ~dot?,
          ~onPress?,
          ~selected?,
          ~icon?,
          ~selectedIcon?,
          ~title?,
          ~key=?key_,
          ~id?,
          ~className?,
          ~style?,
          (),
        ),
      children,
    );
};

module Tab = {
  [@bs.module] external item: ReasonReact.reactClass = "antd-mobile/lib/tab-bar/Tab";

  [@bs.obj] external makeProps: (~id: string=?, ~className: string=?, ~style: ReactDOMRe.Style.t=?, unit) => _ = "";
  let make = (~id=?, ~className=?, ~style=?, children) =>
    ReasonReact.wrapJsForReason(~reactClass=item, ~props=makeProps(~id?, ~className?, ~style?, ()), children);
};
