import React from 'react'
import Link from 'next/link'
import Image from 'next/image'

const NavBar = () => {
  return (
    <div className="bg-gray-900 text-white font-serif">
      {/* Header */}
      <header className="flex justify-between items-center p-6 bg-gray-800 shadow-md">
        <div className="text-2xl font-bold flex items-center">
          { <Image
            src="/flashcard.png"
            alt="Logo"
            width={40}
            height={40}
          /> }
          <Link href="/" className="ml-2">Testy.</Link>
        </div>
        <nav className="flex space-x-6">
          <Link href="/about" className="text-lg hover:text-blue-400 py-2 px-4">
            About
          </Link>
          <Link href="/profile" className="text-lg hover:text-blue-400 py-2 px-4">
            My profile
          </Link>
          <Link href="/study" className="text-lg bg-green-600 text-white py-2 px-4 rounded hover:bg-green-700">
            Study sets
          </Link>
        </nav>
      </header>
      </div>
  )
}


export default NavBar;