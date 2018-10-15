# bs-ant-design-mobile

## Introduction

** See [bs-ant-design](https://github.com/thangngoc89/bs-ant-design) repo for original credit on this pattern. **

Bucklescript + ReasonReact binding for [Ant Design Mobile](https://mobile.ant.design) components. I write bindings when I needed them in my projects. 
If you find a component is missing, it's because I don't need it (yet).

Difference from [bs-antd](https://github.com/tiensonqin/bs-antd) style of bindings: It uses the official recommended way for writing bindings and it doesn't work for me. Best explained this in this [blog post](https://khoanguyen.me/writing-reason-react-bindings-the-right-way/)

Cautionary note that I am very new to bindings so confirmation and testing is necessary for anything you want to use as I only tested what I use.

## Installation

* With npm:

```
npm install --save bs-ant-design-mobile
```

* With yarn:

```
yarn add bs-ant-design-mobile
```

* Add `bs-ant-design-mobile` to `bs-dependencies` in `bsconfig.json`.
* You also need to set up your bundler to handle less files (This is a requirement from ant-design-mobile)

For webpack, you can do this:

```
npm install --save-dev less@^2.7.3 less-loader css-loader style-loader
```

(`less@^2.7.3` is the important bit)

Now add this to your webpack config:

```js
// webpack.config.js
module.exports = {
    ...
    module: {
        rules: [{
        test: /\.less$/,
        use: ["style-loader", "css-loader", "less-loader"]
    }]
}
};
```

## Usage

Please check [ant design's documentation for each component](https://mobile.ant.design/components).

I tried to keep the API as close to the original JS API as possible.

Some common patterns I tried to use:

* string enums -> polymorphic variants
* function argument accepts different types: GDATs or `%identity` hack.

## Components

I did the components I needed.  While I usually made an attempt to do all the params technically, I only tested the
ones I needed.  Assume you will need to test everything you want to use well.

## Contributions

All contributions are welcomed.  I intend to merge and release anything you push quickly.

## LICENSE

MIT
