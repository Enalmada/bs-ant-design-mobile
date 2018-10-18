/* [%bs.raw {|require("antd-mobile/lib/toast/style")|}]; */

/*
 Toast.success(content, duration, onClose, mask)
 Toast.fail(content, duration, onClose, mask)
 Toast.info(content, duration, onClose, mask)
 Toast.loading(content, duration, onClose, mask)
 Toast.offline(content, duration, onClose, mask)
 */

/*
 content	Toast content	React.Element or String	-
 duration	Delay time to close, which units is second	number	3
 onClose	A callback function Triggered when the Toast is closed	Function	-
 mask	Whether to show a transparent mask, which will prevent touch event of the whole page	Boolean
 */

type content = ReasonReact.reactElement;
type duration = int;
type options;
type onClose = (. unit) => unit;
type mask = bool;
[@bs.module "antd-mobile/lib/toast"] external success: (content, duration, onClose, mask) => unit = "";
[@bs.module "antd-mobile/lib/toast"] external fail: (content, duration, onClose, mask) => unit = "";
[@bs.module "antd-mobile/lib/toast"] external info: (content, duration, (. unit) => unit, mask) => unit = "";
[@bs.module "antd-mobile/lib/toast"] external loading: (content, duration, onClose, mask) => unit = "";
[@bs.module "antd-mobile/lib/toast"] external offline: (content, duration, onClose, mask) => unit = "";

[@bs.module "antd-mobile/lib/toast"] external hide: unit => unit = "";
