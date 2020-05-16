[@bs.val] external setTimeout: (unit => unit, int) => float = "setTimeout";
[@bs.scope "fetchMock"] [@bs.val] external mockIf: (string, unit => Js.Promise.t('a)) => unit = "mockIf";
[@bs.scope "fetchMock"] [@bs.val] external resetMocks: (unit) => unit = "resetMocks";
[@bs.module "react-dom/test-utils"] [@bs.val] external act: (unit => unit) => unit = "act";

open Jest;
open Expect;
open Enzyme;
open Enzyme.Mount;
open UseFetch;
open Js.Global;

module ExampleComponent {
  [@react.component]
  let make = () => {
    let response = useFetch("foo.com");
    let result = switch (response) {
      | Fetching => "loading"
      | Fetched(w: WeatherData.t) => string_of_int(w.current.temp_c) ++ w.current.condition.text;
      | FailedToFetch => "error"
    };

    <div>{React.string(result)}</div>;
  }
}

describe("<UseFetch />", () => {
  beforeEach(() => {
    mockIf("foo.com", () => {
      let response = {|{
        "current": {
          "temp_c": "20",
          "condition": {
            "text": "Cloudy"
          }
        }
      }|};

      Js.Promise.make((~resolve, ~reject) => resolve(. response));
    });
  });


  afterEach(() => {
    resetMocks();
  });

  testAsync("initially goes to the loading mode", (finish) => {
    let example = mount(<ExampleComponent />);
    let outcome = example |> text;

    expect(outcome) |> toEqual("loading") |> finish;
  });

  testAsync("upon arrival of response, returns it to the consumer", (finish) => {
    let example = mount(<ExampleComponent />);

    setTimeout(() => {
      let outcome = example |> text;
      expect(outcome) |> toEqual("20Cloudy") |> finish;
      ();
    }, 1) |> ignore;
  });

  testAsync("upon failure of request, returns the error to the consumer", (finish) => {
    mockIf("foo.com", () => {
      Js.Promise.make((~resolve, ~reject) => resolve(. "invalid-json"));
    });

    let example = mount(<ExampleComponent />);

    setTimeout(() => {
      let outcome = example |> text;
      expect(outcome) |> toEqual("error") |> finish;
      ();
    }, 1) |> ignore;
  });
});
