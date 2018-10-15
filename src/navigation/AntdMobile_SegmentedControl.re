[@bs.module] external reactClass: ReasonReact.reactClass = "antd-mobile/lib/segmented-control";

/*
 [%bs.raw {|require("antd-mobile/lib/segmented-control/style")|}];
 */

/* 2.2.5
   prefixCls	prefix class	String	am-segment
   className	class name of component	String
   style	style of component	Object	{}
   tintColor	accent color of the control	String	#2DB7F5
   disabled	whether the user is able to interact with the control	Boolean	false
   selectedIndex	the index in props.values of the segment to be (pre)selected	Number	0
   values	The labels for the control's segment buttons, in order	array	[]
   onChange	callback that is called when the user taps a segment; passes the event object as an argument. e.nativeEvent.selectedSegmentIndex is selected index. e.nativeEvent.value is selected value.	(e): void	function(){}
   onValueChange	callback that is called when the user taps a segment; passes the segment's value as an argument	(val): void	function(){}
         */

[@bs.obj]
external makeProps:
  (
    ~prefixCls: string=?,
    ~tintColor: string=?,
    ~disabled: bool=?,
    ~selectedIndex: int=?,
    ~values: array(string)=?,
    ~onChange: ReactEvent.Mouse.t => unit=?,
    ~onValueChange: ReactEvent.Mouse.t => unit=?,
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
      ~tintColor=?,
      ~disabled=?,
      ~selectedIndex=?,
      ~values=?,
      ~onChange=?,
      ~onValueChange=?,
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
        ~tintColor?,
        ~disabled?,
        ~selectedIndex?,
        ~values=?Js.Option.map((. b) => Array.of_list(b), values),
        ~onChange?,
        ~onValueChange?,
        ~id?,
        ~className?,
        ~style?,
        (),
      ),
    children,
  );
