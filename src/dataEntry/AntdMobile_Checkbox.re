[@bs.module "antd-mobile/lib/checkbox"] external reactClass: ReasonReact.reactClass = "default";

/*
 [%bs.raw {|require("antd-mobile/lib/checkbox/style")|}];
 */

/* 2.2.5
   defaultChecked	whether is checked when init	Boolean
   checked	whether is checked now (Controlled Mode)	Boolean
   disabled	whether is been disabled	Boolean	false
   onChange	callback when check status is changed	(e: Object): void
    */

[@bs.obj]
external makeProps:
  (
    ~key: string=?,
    ~defaultChecked: bool=?,
    ~checked: bool=?,
    ~disabled: bool=?,
    ~onChange: unit => unit=?,
    ~multipleLine: bool=?,
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
      ~defaultChecked=?,
      ~checked=?,
      ~disabled=?,
      ~onChange=?,
      ~multipleLine=?,
      ~id=?,
      ~className=?,
      ~style=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      makeProps(
        ~key=?key_,
        ~defaultChecked?,
        ~checked?,
        ~disabled?,
        ~onChange?,
        ~multipleLine?,
        ~id?,
        ~className?,
        ~style?,
        (),
      ),
    children,
  );

module CheckboxItem = {
  /* [@bs.module "antd-mobile/lib/checkbox/CheckboxItem"] external item: ReasonReact.reactClass = "CheckboxItem"; */
  [@bs.module] external item: ReasonReact.reactClass = "antd-mobile/lib/checkbox/CheckboxItem";

  /* 2.2.5

     */

  [@bs.obj]
  external makeProps:
    (
      ~key: string=?,
      ~defaultChecked: bool=?,
      ~checked: bool=?,
      ~disabled: bool=?,
      ~onChange: unit => unit=?,
      ~multipleLine: bool=?,
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
        ~defaultChecked=?,
        ~checked=?,
        ~disabled=?,
        ~onChange=?,
        ~multipleLine=?,
        ~id=?,
        ~className=?,
        ~style=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=item,
      ~props=
        makeProps(
          ~key=?key_,
          ~defaultChecked?,
          ~checked?,
          ~disabled?,
          ~onChange?,
          ~multipleLine?,
          ~id?,
          ~className?,
          ~style?,
          (),
        ),
      children,
    );
};

module AgreeItem = {
  /* [@bs.module "antd-mobile/lib/checkbox/AgreeItem"] external item: ReasonReact.reactClass = "default"; */
  [@bs.module] external item: ReasonReact.reactClass = "antd-mobile/lib/checkbox/AgreeItem";

  /* 2.2.5

     */

  [@bs.obj]
  external makeProps:
    (
      ~key: string=?,
      ~defaultChecked: bool=?,
      ~checked: bool=?,
      ~disabled: bool=?,
      ~onChange: unit => unit=?,
      ~multipleLine: bool=?,
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
        ~defaultChecked=?,
        ~checked=?,
        ~disabled=?,
        ~onChange=?,
        ~multipleLine=?,
        ~id=?,
        ~className=?,
        ~style=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=item,
      ~props=
        makeProps(
          ~key=?key_,
          ~defaultChecked?,
          ~checked?,
          ~disabled?,
          ~onChange?,
          ~multipleLine?,
          ~id?,
          ~className?,
          ~style?,
          (),
        ),
      children,
    );
};
