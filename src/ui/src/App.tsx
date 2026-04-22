import './App.css'

function App() {
  return (
    <>
      <div className="innershell--command">
        <input type="text" placeholder="Search..." style={{width: "100%", height: 40, background: "red"}} />
      </div>

      <div className={"innershell--output"}></div>
    </>
  )
}

export default App
