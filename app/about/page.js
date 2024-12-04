import React from 'react'
import NavBar from '@/components/NavBar'

 const About = () => {
  return (
    <>
    <NavBar/>
      <div className="min-h-screen flex flex-col items-center bg-gray-900">
          <h1 className=" mt-20 text-xl font-semibold text-white">Testy is an app made by students, for students.</h1>
          <div className=" px-6 py-4 my-4 rounded shadow-inner bg-gray-800 max-w-5xl w-full">
            <p className="text-white leading-relaxed text-justify">Our study application is designed to empower university students by providing 
              an intuitive and efficient platform for mastering course material. Whether you're preparing for exams,
              managing flashcards, or organizing study sessions, our app streamlines the process to help you stay on top of your academics. 
              With customizable flashcards, collaborative study features, and progress tracking, it's tailored to fit your unique learning style.
                Built with busy students in mind, our goal is to make studying smarter, not harder, so you can achieve academic success with confidence.
                <br></br>
                <br></br>
                We created this application out of a passion for learning and a deep understanding of the challenges university students face. 
                We believe education should be accessible, engaging, and enjoyable. Our mission is to inspire students to embrace their studies 
                by giving them the tools to succeed, no matter the subject. By fostering a community of learners and encouraging effective study
                 habits, we aim to empower students to reach their full potential and develop a lifelong love for learning.
            </p>
            <h1 className=" mt-20 text-xl font-semibold text-white">By:</h1>
            <h2 className=" mt-5 text-lg text-white">Nolan, Morlae, Chao Wei, & Sweden</h2>
          </div>
      </div>
  </>
  )
}

export default About