type t = {
  token: option(string),
};

let context = React.createContext({ token: None });

module Provider = {
  [@bs.obj]
  external makeProps:
    (~value: t, ~children: React.element, unit) =>
    {
      .
      "value": t,
      "children": React.element,
    };

  let make = context->React.Context.provider;
};
