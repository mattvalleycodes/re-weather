[@react.component]
let make = (~city: string, ~condition: string, ~temp: string) => {
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

  <div style={mainStyle}>
    <h1 id="cityName" style={cityStyle}>{React.string(city)}</h1>
    <div style={conditionStyle}>{React.string(condition)}</div>
    <span style={tempStyle}> {React.string(" - ")} {React.string(temp)}</span>
  </div>
}
