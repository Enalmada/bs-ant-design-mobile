[@bs.module] external reactClass: ReasonReact.reactClass = "antd-mobile/lib/drawer";

/*
 [%bs.raw {|require("antd-mobile/lib/drawer/style")|}];
 */

[@bs.deriving jsConverter]
type position = [ | `left | `right | `top | `bottom];

/* 2.2.5
   sidebar	The sidebar content.	ReactNode	-
   onOpenChange	Callback called when open state of Drawer changes.	(open: bool): void	-
   open	If the sidebar should be open.	Boolean	false
   position	Position of Drawer.	String	'left', enum{'left', 'right', 'top', 'bottom'}
   sidebarStyle	-	Object	{}
   contentStyle	-	Object	{}
   overlayStyle	-	Object	{}
   dragHandleStyle	-	Object	{}
   touch	If touch gestures should be enabled	Boolean	true
   transitions	If transitions should be enabled.	Boolean	true
   docked	If the sidebar should be docked in document.	Boolean	false
   enableDragHandle	If dragHandle should be enabled	Boolean	false
   dragToggleDistance	Distance the sidebar has to be dragged before it will open/close after it is released.	Number	30
      */

[@bs.obj]
external makeProps:
  (
    ~sidebar: ReasonReact.reactElement=?,
    ~onOpenChange: unit => unit=?,
    ~_open: bool=?,
    ~position: string=?,
    ~sidebarStyle: ReactDOMRe.Style.t=?,
    ~contentStyle: ReactDOMRe.Style.t=?,
    ~overlayStyle: ReactDOMRe.Style.t=?,
    ~dragHandleStyle: ReactDOMRe.Style.t=?,
    ~touch: bool=?,
    ~transitions: bool=?,
    ~docked: bool=?,
    ~enableDragHandle: bool=?,
    ~dragToggleDistance: int=?,
    ~id: string=?,
    ~className: string=?,
    ~style: ReactDOMRe.Style.t=?,
    unit
  ) =>
  _ =
  "";

let make =
    (
      ~sidebar=?,
      ~onOpenChange=?,
      ~_open=?,
      ~position=?,
      ~sidebarStyle=?,
      ~contentStyle=?,
      ~overlayStyle=?,
      ~dragHandleStyle=?,
      ~touch=?,
      ~transitions=?,
      ~docked=?,
      ~enableDragHandle=?,
      ~dragToggleDistance=?,
      ~id=?,
      ~className=?,
      ~style=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      makeProps(
        ~sidebar?,
        ~onOpenChange?,
        ~_open?,
        ~position=?Js.Option.map((. b) => positionToJs(b), position),
        ~sidebarStyle?,
        ~contentStyle?,
        ~overlayStyle?,
        ~dragHandleStyle?,
        ~touch?,
        ~transitions?,
        ~docked?,
        ~enableDragHandle?,
        ~dragToggleDistance?,
        ~id?,
        ~className?,
        ~style?,
        (),
      ),
    children,
  );
