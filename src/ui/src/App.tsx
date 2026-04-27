import './App.css'
import {type FC, useEffect, useState} from "react";

// @ts-ignore
window.saucer = window.saucer || {};

export const App: FC = () => {
    const [search, setSearch] = useState("");

    const handleSearch = async () => {
        // @ts-ignore
        await saucer.exposed.search(false);
    }

    useEffect(() => {
        // todo bounce off

        handleSearch().catch(console.error);
    }, [search])

  return (
    <>
      <div className="innershell--command">
        <input
            type="text"
            onChange={(e) => setSearch(e.target.value)}
            value={search}
            placeholder="Search..."
            style={{width: "100%", height: 40, background: "red"}} />
      </div>

      <div className={"innershell--output"}></div>
    </>
  )
};
