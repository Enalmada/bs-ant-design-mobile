[@bs.module] external reactClass: ReasonReact.reactClass = "antd-mobile/lib/badge";

/*
 [%bs.raw {|require("antd-mobile/lib/badge/style")|}];
 */

[@bs.deriving jsConverter]
type size = [ | `large | `small];

/* 2.2.5
   size	size of badge, optional: large small	string	small
   text	text or number inside badge	string|number	-
   corner	whether is badge at corner position	boolean	false
   dot	show badge as a red dot	boolean	false
   overflowCount	max count to show	number	99
   hot	hot commercial style	boolean	false
             */

[@bs.obj]
external makeProps:
  (
    ~size: string=?,
    ~text: string=?,
    ~corner: bool=?,
    ~dot: bool=?,
    ~overflowCount: int=?,
    ~hot: bool=?,
    ~id: string=?,
    ~className: string=?,
    ~style: ReactDOMRe.Style.t=?,
    unit
  ) =>
  _ =
  "";

let make = (~size=?, ~text=?, ~corner=?, ~dot=?, ~overflowCount=?, ~hot=?, ~id=?, ~className=?, ~style=?, children) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=makeProps(~size?, ~text?, ~corner?, ~dot?, ~overflowCount?, ~hot?, ~id?, ~className?, ~style?, ()),
    children,
  );
