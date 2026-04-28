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

    const handleEvent = async (e: any) => {
        setSearch(e.target.value)
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
      <div className="innershell--command">
        <input
            type="text"
            onChange={handleEvent}
            value={search}
            placeholder="Search..."
            style={{width: "100%", height: "80px"}} />
      </div>

      <div className={"innershell--output"}></div>
    </>
  )
};
