[@bs.module] external reactClass: ReasonReact.reactClass = "antd-mobile/lib/button";

/*
 [%bs.raw {|require("antd-mobile/lib/button/style")|}];
 */

[@bs.deriving jsConverter]
type buttonType = [ | `primary | `ghost | `warning];

[@bs.deriving jsConverter]
type buttonSize = [ | `small | `default | `large];

module LoadingProps = {
  type delay = {. "delay": int};
  type t =
    | Bool(bool)
    | Delay(delay);
  type js;
  external ofBool: bool => js = "%identity";
  external ofDelay: delay => js = "%identity";
  let toJs: t => js =
    fun
    | Bool(a) => a |> ofBool
    | Delay(a) => a |> ofDelay;
};

/* 2.2.5
   type	can be set to primary/ghost/warning or omitted	string	-
   size	can be set to large?small or omitted	string	large
   activeStyle	the feedback's custom style (set to false to disable click feedback)	{}/false	{}
   activeClassName	the feedback's custom class name	string
   disabled	set disabled	boolean	false
   onClick	set the handler to handle click event	(e: Object): void	-
   style	custom style	Object	-
   inline	whether set as an inline button	boolean	false
   loading	whether set loading state	boolean	false
   icon	can be set to one type value of the Icon Component or any valid React.Element. (Note: It will be overwritten by the loading setting)	string/React.Element	-
   prefixCls	prefix class	string	am-button
   className	class name	string	''

   */

[@bs.obj]
external makeProps:
  (
    ~_type: string=?,
    ~size: string=?,
    ~activeStyle: ReactDOMRe.Style.t=?,
    ~activeClassName: string=?,
    ~disabled: bool=?,
    ~onClick: ReactEvent.Mouse.t => unit=?,
    ~style: ReactDOMRe.Style.t=?,
    ~inline: bool=?,
    ~loading: LoadingProps.js=?,
    ~icon: string=?,
    ~prefixCls: string=?,
    ~id: string=?,
    ~className: string=?,
    unit
  ) =>
  _ =
  "";

let make =
    (
      ~_type=?,
      ~size=?,
      ~activeStyle=?,
      ~activeClassName=?,
      ~disabled=?,
      ~onClick=?,
      ~style=?,
      ~inline=?,
      ~loading: option(LoadingProps.t)=?,
      ~icon=?,
      ~prefixCls=?,
      ~id=?,
      ~className=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      makeProps(
        ~_type=?Js.Option.map((. b) => buttonTypeToJs(b), _type),
        ~size=?Js.Option.map((. b) => buttonSizeToJs(b), size),
        ~activeStyle?,
        ~activeClassName?,
        ~disabled?,
        ~onClick?,
        ~style?,
        ~inline?,
        ~loading=?Js.Option.map((. b) => LoadingProps.toJs(b), loading),
        ~icon?,
        ~prefixCls?,
        ~id?,
        ~className?,
        (),
      ),
    children,
  );
