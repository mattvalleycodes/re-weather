[@bs.val] external fetch: string => Js.Promise.t('a) = "fetch";
open React;

type fetchState =
  | LoadingWeatherInfo
  | ErrorLoadingWeatherInfo
  | LoadedWeatherInfo(int, string);

let useFetch = (url) => {
  let (response, setResponse) = useState(() => LoadingWeatherInfo);

  useEffect1(() => {
    Js.Promise.(
      fetch(url)
      |> then_(response => response##json())
      |> then_(jsonResponse => {
           setResponse(_previousState => LoadedWeatherInfo(jsonResponse##current##temp_c, jsonResponse##current##condition##text));
           Js.Promise.resolve();
         })
      |> catch(_err => {
           setResponse(_previousState => ErrorLoadingWeatherInfo);
           Js.Promise.resolve();
         })
      |> ignore
    );

    None;
  }, [|url|]);

  response;
}
