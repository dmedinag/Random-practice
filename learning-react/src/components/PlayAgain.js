import React from 'react'

const PlayAgain = (props) => (
  <div className="game-done">
    <div
      className="message"
      style={{
        color: props.status === 'lost' ? 'red' : 'green',
      }}
    >
      You {props.status}{' '}
    </div>{' '}
    <button onClick={props.onClick}> Play again </button>{' '}
  </div>
)

export default PlayAgain
