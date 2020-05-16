[@bs.val] external fetch: string => Js.Promise.t('a) = "fetch";

open React;

type fetchState('a) =
  | Fetching
  | FailedToFetch
  | Fetched('a);

let useFetch = (url) => {
  let (response, setResponse) = useState(() => Fetching);

  useEffect1(() => {
    Js.Promise.(
      fetch(url)
      |> then_(response => response##json())
      |> then_(jsonResponse => {
           setResponse(_previousState => Fetched(jsonResponse));
           Js.Promise.resolve();
         })
      |> catch(_err => {
           setResponse(_previousState => FailedToFetch);
           Js.Promise.resolve();
         })
      |> ignore
    );

    None;
  }, [|url|]);

  response;
}
