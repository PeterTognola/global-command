import './App.css'
import {type FC, useEffect, useState} from "react";
import {ResultComponent} from "./components/ResultComponent.tsx";

// @ts-ignore
window.saucer = window.saucer || {};

export type Result = {
    name: string;
}

export const App: FC = () => {
    const [search, setSearch] = useState("");
    const [results, setResults] = useState<Result[]>([{name: "test"}]);

    const handleSearch = async () => {
        // @ts-ignore
        //await saucer.exposed.search(false);
        setResults([{name: "test"}]);

        // @ts-ignore
        await saucer.exposed.expand(search.length > 0 ? results.length * 30 : 0);
    }

    const handleEvent = async (e: any) => {
        const input = e.target.value;
        setSearch(input);
    }

    useEffect(() => {
        // todo bounce off
        handleSearch().catch(console.error);
    }, [search]);

    useEffect(() => {
        document.body.addEventListener('keydown', async function(e) {
            if (e.key == "Escape") {
                //@ts-ignore
                await saucer.exposed.close();
            }
        });
    }, []);

  return (
    <>
      <div className="command">
        <input
            type="text"
            onChange={handleEvent}
            value={search}
            placeholder="Search..."
            style={{width: "100%", height: "80px", outline: 0, border: 0}} />
      </div>

        {search.length > 0 &&
          <div className={"output"}>
              {results.map((r: Result, i: number) => <ResultComponent key={i} result={r} />)}
          </div>
        }
    </>
  )
};
