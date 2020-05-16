type lt = {
  search: string,
};

[@bs.val]
external location: lt = "location";

let citiesStyle = ReactDOMRe.Style.make(
  ~listStyle="none",
  ~padding="0",
  ~margin="0",
  ()
);

let cityStyle = ReactDOMRe.Style.make(
  ~margin="0 0 10px 0",
  ()
);

let toWeather = (c) => {
  <li style={cityStyle} key={c}>
    <Weather city={c} />
  </li>
};

let cities = [|
  "Sydney",
  "San Francisco",
  "Tehran"
|];

[@react.component]
let make = () => {
  open Utils;

  let token = qs(location.search)[0];

  let source = cities
    -> Belt.Array.map(toWeather)
    -> React.array;

  let context: WeatherContext.t = {
    token: Some(token.value),
  };

  <WeatherContext.Provider value={context}>
    <ul style={citiesStyle}>{source}</ul>
  </WeatherContext.Provider>
}
