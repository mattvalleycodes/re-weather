open UseFetch;

let mainStyle = ReactDOMRe.Style.make(
  ~border="1px solid #48a9dc",
  ~borderRadius="5px",
  ~padding="10px",
  ~display="inline-block",
  ~minWidth="100px",
  ()
);

let cityStyle = ReactDOMRe.Style.make(
  ~display="block",
  ~margin="0",
  ~padding="0",
  ~fontSize="20px",
  ~color="#48a9dc",
  ()
);

let conditionStyle = ReactDOMRe.Style.make(
  ~padding="10px 0 10px 0",
  ~color="#717171",
  ~fontSize="14px",
  ~display="inline-block",
  ()
);

let tempStyle = ReactDOMRe.Style.make(
  ~padding="10px 0 10px 0",
  ~color="#717171",
  ~fontSize="14px",
  ()
);

[@react.component]
let make = (~city: string) => {
  let context = React.useContext(WeatherContext.context);

  switch(context.token) {
  | None => <div>{React.string("missing API token")}</div>
  | Some(token) => {
      let url = "http://api.weatherapi.com/v1/current.json?key=" ++ token ++ "&q=" ++ city;

      switch(useFetch(url)) {
        | Fetching => <div>{React.string("Loading weather info for" ++ city)}</div>
        | FailedToFetch => <div>{React.string("Failed to fetch weather info for" ++ city)}</div>
        | Fetched(weather: WeatherData.t) => {
            <div style={mainStyle}>
              <h1 id="cityName" style={cityStyle}>{React.string(city)}</h1>
              <div style={conditionStyle}>{React.string(weather.current.condition.text)}</div>
              <span style={tempStyle}>{React.string(" - " ++ string_of_int(weather.current.temp_c))}</span>
            </div>
        }
      }
    }
  }
}
