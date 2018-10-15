[@bs.module] external reactClass: ReasonReact.reactClass = "antd-mobile/lib/search-bar";

/*
 [%bs.raw {|require("antd-mobile/lib/search-bar/style")|}];
 */

/* 2.2.5
   defaultValue	the uncontrolled default value	String
   value	the controlled current value	String
   placeholder	placeholder	String
   onSubmit	submit event (click the enter on the keyboard)	(val: string): void
   onChange	change event callback	(val: string): void
   onFocus	focus event callback	(): void
   onBlur	blur event callback	(): void
   onCancel	Click the Cancel button to trigger (The text of the input box is no longer automatically cleared)	(val: string): void
   showCancelButton	Whether the Cancel button is always displayed	bool	false
   cancelText	Customize the text of the Cancel button	String	??
   disabled	Set disabled	bool	false
   onClear	Click the clear icon to trigger	(val: string): void
   maxLength	The maxlength attribute limits the number of characters that SearchBar can accept	number	-
       */

[@bs.obj]
external makeProps:
  (
    ~defaultValue: string=?,
    ~value: string=?,
    ~placeholder: string=?,
    ~onSubmit: string => unit=?,
    ~onChange: string => unit=?,
    ~onFocus: unit => unit=?,
    ~onBlur: unit => unit=?,
    ~onCancel: string => unit=?,
    ~showCancelButton: bool=?,
    ~cancelText: string=?,
    ~disabled: bool=?,
    ~onClear: string => unit=?,
    ~maxLength: int=?,
    ~id: string=?,
    ~className: string=?,
    ~style: ReactDOMRe.Style.t=?,
    unit
  ) =>
  _ =
  "";

let make =
    (
      ~defaultValue=?,
      ~value=?,
      ~placeholder=?,
      ~onSubmit=?,
      ~onChange=?,
      ~onFocus=?,
      ~onBlur=?,
      ~onCancel=?,
      ~showCancelButton=?,
      ~cancelText=?,
      ~disabled=?,
      ~onClear=?,
      ~maxLength=?,
      ~id=?,
      ~className=?,
      ~style=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      makeProps(
        ~defaultValue?,
        ~value?,
        ~placeholder?,
        ~onSubmit?,
        ~onChange?,
        ~onFocus?,
        ~onBlur?,
        ~onCancel?,
        ~showCancelButton?,
        ~cancelText?,
        ~disabled?,
        ~onClear?,
        ~maxLength?,
        ~id?,
        ~className?,
        ~style?,
        (),
      ),
    children,
  );
