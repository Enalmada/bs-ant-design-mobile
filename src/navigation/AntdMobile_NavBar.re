[@bs.module] external reactClass: ReasonReact.reactClass = "antd-mobile/lib/nav-bar";

/*
 [%bs.raw {|require("antd-mobile/lib/nav-bar/style")|}];
 */

[@bs.deriving jsConverter]
type mode = [ | `dark | `light];

/* 2.2.5
   mode	style mode	string	'dark' enum{'dark', 'light'}
   icon	appears on the leftmost icon placeholder	ReactNode	-
   leftContent	left content	any	-
   rightContent	right content	any	-
   onLeftClick	click the callback on the left	(e: Object): void	-
       */

[@bs.obj]
external makeProps:
  (
    ~mode: string=?,
    ~icon: ReasonReact.reactElement=?,
    ~leftContent: array(ReasonReact.reactElement)=?,
    ~rightContent: array(ReasonReact.reactElement)=?,
    ~onLeftClick: unit => unit=?,
    ~id: string=?,
    ~className: string=?,
    ~style: ReactDOMRe.Style.t=?,
    unit
  ) =>
  _ =
  "";

let make =
    (~mode=?, ~icon=?, ~leftContent=?, ~rightContent=?, ~onLeftClick=?, ~id=?, ~className=?, ~style=?, children) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      makeProps(
        ~mode=?Js.Option.map((. b) => modeToJs(b), mode),
        ~icon?,
        ~leftContent=?Js.Option.map((. b) => Array.of_list(b), leftContent),
        ~rightContent=?Js.Option.map((. b) => Array.of_list(b), rightContent),
        ~onLeftClick?,
        ~id?,
        ~className?,
        ~style?,
        (),
      ),
    children,
  );
