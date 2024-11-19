import React from "react";

 const Button = ( { onClick, label}) => {
  return (
<button onClick={onClick} className="bg-blue-800 text-white py-3 px-8 rounded-full text-xl transform transition-transform duration-300 hover:scale-105 hover:bg-blue-600">
{label}
</button>
  )
}

export default Button;