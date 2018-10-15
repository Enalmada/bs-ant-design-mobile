[@bs.module "antd-mobile/lib/tabs"] external reactClass: ReasonReact.reactClass = "default";

/*
 [%bs.raw {|require("antd-mobile/lib/tabs/style")|}];
 */

[@bs.deriving abstract]
type tabData = {
  .
  "title": ReasonReact.reactElement,
  "sub": string,
};

[@bs.deriving jsConverter]
type tabBarPosition = [ | `top | `bottom | `left | `right];

[@bs.deriving jsConverter]
type tabDirection = [ | `horizontal | `vertical];

/* 2.2.5
   prefixCls	prefix class	string	rmc-tabs	false
   tabs	tabs data	Models.TabData[]		true
   tabBarPosition	TabBar's position	'top' | 'bottom' | 'left' | 'right'	top	false
   renderTabBar	replace the TabBar	((props: TabBarPropsType) => React.ReactNode) | false		false
   initialPage	the tab when inital, index or key	number | string		false
   page	current tab, index or key	number | string		false
   swipeable	Whether to switch tabs with swipe gestrue in the content	boolean	true	false
   useOnPan	use hand scroll	boolean	true	false
   prerenderingSiblingsNumber	pre-render nearby # sibling, Infinity: render all the siblings, 0: render current page.	number	1	false
   animated	Whether to change tabs with animation	boolean	true	false
   onChange	Callback when tab is switched	(tab: Models.TabData, index: number) => void		false
   onTabClick	on tab click	(tab: Models.TabData, index: number) => void		false
   destroyInactiveTab	destroy inactive tab	boolean	false	false
   distanceToChangeTab	distance to change tab, width ratio	number	0.3	false
   usePaged	use paged	boolean	true	false
   tabDirection	tab paging direction	'horizontal' | 'vertical'	horizontal	false
   tabBarUnderlineStyle	style of the default tab bar's underline	React.CSSProperties | any		false
   tabBarBackgroundColor	color of the default tab bar's background	string		false
   tabBarActiveTextColor	color of the default tab bar's text when active	string		false
   tabBarInactiveTextColor	color of the default tab bar's text when inactive	string		false
   tabBarTextStyle	tional styles to the tab bar's text	React.CSSProperties | any		false
   renderTab	render for replace the tab of tabbar	(tab: Models.TabData) => React.ReactNode		false
          */

[@bs.obj]
external makeProps:
  (
    ~prefixCls: string=?,
    ~tabs: array(tabData)=?,
    ~tabBarPosition: string=?,
    ~renderTabBar: Js.t('a) => ReasonReact.reactElement=?,
    ~initialPage: int=?,
    ~page: int=?,
    ~swipeable: bool=?,
    ~useOnPan: bool=?,
    ~prerenderingSiblingsNumber: int=?,
    ~animated: bool=?,
    ~onChange: (tabData, int) => unit=?,
    ~onTabClick: (tabData, int) => unit=?,
    ~destroyInactiveTab: bool=?,
    ~distanceToChangeTab: float=?,
    ~usePaged: bool=?,
    ~tabDirection: string=?,
    ~tabBarUnderlineStyle: ReactDOMRe.Style.t=?,
    ~tabBarBackgroundColor: string=?,
    ~tabBarActiveTextColor: string=?,
    ~tabBarInactiveTextColor: string=?,
    ~tabBarTextStyle: ReactDOMRe.Style.t=?,
    ~renderTab: Js.t('a) => ReasonReact.reactElement=?,
    ~id: string=?,
    ~className: string=?,
    ~style: ReactDOMRe.Style.t=?,
    unit
  ) =>
  _ =
  "";

let make =
    (
      ~prefixCls=?,
      ~tabs=?,
      ~tabBarPosition=?,
      ~renderTabBar=?,
      ~initialPage=?,
      ~page=?,
      ~swipeable=?,
      ~useOnPan=?,
      ~prerenderingSiblingsNumber=?,
      ~animated=?,
      ~onChange=?,
      ~onTabClick=?,
      ~destroyInactiveTab=?,
      ~distanceToChangeTab=?,
      ~usePaged=?,
      ~tabDirection=?,
      ~tabBarUnderlineStyle=?,
      ~tabBarBackgroundColor=?,
      ~tabBarActiveTextColor=?,
      ~tabBarInactiveTextColor=?,
      ~tabBarTextStyle=?,
      ~renderTab=?,
      ~id=?,
      ~className=?,
      ~style=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      makeProps(
        ~prefixCls?,
        ~tabs=?Js.Option.map((. b) => Array.of_list(b), tabs),
        ~tabBarPosition=?Js.Option.map((. b) => tabBarPositionToJs(b), tabBarPosition),
        ~renderTabBar?,
        ~initialPage?,
        ~page?,
        ~swipeable?,
        ~useOnPan?,
        ~prerenderingSiblingsNumber?,
        ~animated?,
        ~onChange?,
        ~onTabClick?,
        ~destroyInactiveTab?,
        ~distanceToChangeTab?,
        ~usePaged?,
        ~tabDirection?,
        ~tabBarUnderlineStyle?,
        ~tabBarBackgroundColor?,
        ~tabBarActiveTextColor?,
        ~tabBarInactiveTextColor?,
        ~tabBarTextStyle?,
        ~renderTab?,
        ~id?,
        ~className?,
        ~style?,
        (),
      ),
    children,
  );

/*
 goToTab	call this function to switch Tab	(index: number) => boolean		true
 tabs	tabs data	Models.TabData[]		true
 activeTab	current tab	number		true
 animated	Whether to change tabs with animation	boolean		true
 prefixCls	prefix class	string	am-tabs-default-bar	false
 renderTab	render for replace the tab of tabbar	(tab: Models.TabData) => React.ReactNode		false
 page	the size for the tab of tabbar	number	5	false
 onTabClick	on tab click	(tab: Models.TabData, index: number) => void		false
 */

module DefaultTabBar = {
  [@bs.module "antd-mobile/lib/tabs"] external defaultTabBar: ReasonReact.reactClass = "DefaultTabBar";
  [@bs.obj]
  external makeProps:
    (
      ~key: string=?,
      ~goToTab: int => bool=?,
      ~tabs: array(tabData)=?,
      ~activeTab: int=?,
      ~animated: bool=?,
      ~prefixCls: string=?,
      ~renderTab: tabData => ReasonReact.reactElement=?,
      ~page: int=?,
      ~onTabClick: (tabData, int) => unit=?,
      ~id: string=?,
      ~className: string=?,
      ~style: ReactDOMRe.Style.t=?,
      unit
    ) =>
    _ =
    "";
  let make =
      (
        ~key_=?,
        ~goToTab=?,
        ~tabs=?,
        ~activeTab=?,
        ~animated=?,
        ~prefixCls=?,
        ~renderTab=?,
        ~page=?,
        ~onTabClick=?,
        ~id=?,
        ~className=?,
        ~style=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=defaultTabBar,
      ~props=
        makeProps(
          ~key=?key_,
          ~goToTab?,
          ~tabs=?Js.Option.map((. b) => Array.of_list(b), tabs),
          ~activeTab?,
          ~animated?,
          ~prefixCls?,
          ~renderTab?,
          ~page?,
          ~onTabClick?,
          ~id?,
          ~className?,
          ~style?,
          (),
        ),
      children,
    );
};
