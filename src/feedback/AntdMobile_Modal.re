[@bs.module] external reactClass: ReasonReact.reactClass = "antd-mobile/lib/modal";

/*
 [%bs.raw {|require("antd-mobile/lib/modal/style")|}];
 */

/* 2.2.5
   visible	Determine whether a modal dialog is visible or not	Boolean	false
   closable	Determine whether a close (x) button is visible or not	Boolean	false
   maskClosable	Determine whether to close the modal dialog when clicked mask of it	Boolean	true
   onClose	Callback for clicking close icon x or mask	(): void	-
   transparent	transparent mode or full screen mode	Boolean	false
   popup	popup mode	Boolean	false
   animationType	Options: 'slide-down / up' / 'fade' / 'slide'	String	fade
   title	title	React.Element	-
   footer	footer content	Array {text, onPress}	[]
   platform	set the special style depends on platform, Options android, ios	String	ios
   transitionName	Modal animation css class name	String
   maskTransitionName	mask animation css class name	String
   className	additional className for dialog	String
   wrapClassName	additional className for dialog wrap	String

                */

[@bs.deriving jsConverter]
type animationType = [ | [@bs.as "slide-down"] `slideDown | [@bs.as "slide-up"] `slideUp | `fade | `slide];

[@bs.deriving jsConverter]
type platform = [ | `android | `ios];

[@bs.deriving abstract]
type footer = {
  text: string,
  onPress: unit => unit,
};

[@bs.obj]
external makeProps:
  (
    ~visible: bool=?,
    ~closable: bool=?,
    ~maskClosable: bool=?,
    ~onClose: unit => unit=?,
    ~transparent: bool=?,
    ~popup: bool=?,
    ~animationType: string=?,
    ~title: ReasonReact.reactElement=?,
    ~footer: array(footer)=?,
    ~platform: string=?,
    ~transitionName: string=?,
    ~maskTransitionName: string=?,
    ~wrapClassName: string=?,
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
      ~closable=?,
      ~maskClosable=?,
      ~onClose=?,
      ~transparent=?,
      ~popup=?,
      ~animationType=?,
      ~title=?,
      ~footer=?,
      ~platform=?,
      ~transitionName=?,
      ~maskTransitionName=?,
      ~wrapClassName=?,
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
        ~closable?,
        ~maskClosable?,
        ~onClose?,
        ~transparent?,
        ~popup?,
        ~animationType=?Js.Option.map((. b) => animationTypeToJs(b), animationType),
        ~title?,
        ~footer=?Js.Option.map((. b) => Array.of_list(b), footer),
        ~platform=?Js.Option.map((. b) => platformToJs(b), platform),
        ~transitionName?,
        ~maskTransitionName?,
        ~wrapClassName?,
        ~id?,
        ~className?,
        ~style?,
        (),
      ),
    children,
  );
