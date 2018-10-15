[@bs.module] external reactClass: ReasonReact.reactClass = "antd-mobile/lib/grid";

/*
 [%bs.raw {|require("antd-mobile/lib/grid/style")|}];
 */

[@bs.deriving abstract]
type dataProps = {
  icon: string,
  text: string,
};

/* 2.2.5
   data	data record array to be rendered	Array<{icon, text}>	[]
   onClick	Handler to be called when the user taps the grid	(el: Object, index: number): void	-
   columnNum	the number of columns	number	4
   hasLine	whether to show border	boolean	true
   isCarousel	whether to be played as a Carousel	boolean	false
   carouselMaxRow	the max number of rows to be showed each page of the Carousel	number	2
   renderItem	custom function to create each grid item	(el, index) => React.Node	-
   square	whether each item restrict to a square	boolean	true
   activeStyle	the feedback's custom style (set to false to disable click feedback)	{}/false	{}
   activeClassName	the feedback's custom class name	string
   itemStyle	Custom GridCell Style	object	{}

        */

[@bs.obj]
external makeProps:
  (
    ~data: array(dataProps)=?,
    ~onClick: 'a => unit=?,
    ~columnNum: int=?,
    ~hasLine: bool=?,
    ~isCarousel: bool=?,
    ~carouselMaxRow: int=?,
    ~renderItem: Js.t('a) => ReasonReact.reactElement=?,
    ~square: bool=?,
    ~activeStyle: ReactDOMRe.Style.t=?,
    ~activeClassName: string=?,
    ~itemStyle: ReactDOMRe.Style.t=?,
    ~id: string=?,
    ~className: string=?,
    ~style: ReactDOMRe.Style.t=?,
    unit
  ) =>
  _ =
  "";

let make =
    (
      ~data=?,
      ~onClick=?,
      ~columnNum=?,
      ~hasLine=?,
      ~isCarousel=?,
      ~carouselMaxRow=?,
      ~renderItem=?,
      ~square=?,
      ~activeStyle=?,
      ~activeClassName=?,
      ~itemStyle=?,
      ~id=?,
      ~className=?,
      ~style=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      makeProps(
        ~data=?Js.Option.map((. b) => Array.of_list(b), data),
        ~onClick?,
        ~columnNum?,
        ~hasLine?,
        ~isCarousel?,
        ~carouselMaxRow?,
        ~renderItem?,
        ~square?,
        ~activeStyle?,
        ~activeClassName?,
        ~itemStyle?,
        ~id?,
        ~className?,
        ~style?,
        (),
      ),
    children,
  );
