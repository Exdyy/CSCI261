#include <SFML/Graphics.hpp>
using namespace sf;

int main() {
    // create a window
    RenderWindow window( VideoMode(640, 640), "SFML Test" );

    /////////////////////////////////////
    // BEGIN ANY FILE LOADING

    // perform any file processing once before draw loop begins

    //  END  ANY FILE LOADING
    /////////////////////////////////////

    // create an event object once to store future events
    Event event;

    // while the window is open
    while( window.isOpen() ) {
        // clear any existing contents
        window.clear();

        /////////////////////////////////////
        // BEGIN DRAWING HERE

        // Draw a circle object called star and color it yellow
        CircleShape head;
        head.setPosition( 15, 15 );
        head.setRadius(300 );
        head.setFillColor( Color::Red );
        window.draw( head);
                
        // Draw a rectangle object called rect and color it blue
        RectangleShape leftEye;
        leftEye.setSize( Vector2f( 25, 100 ) );
        leftEye.setPosition( 200, 150 );
        leftEye.setFillColor( Color(0, 0, 255));
        window.draw( leftEye );

        RectangleShape rightEye;
        rightEye.setSize( Vector2f( 25, 100 ) );
        rightEye.setPosition( 400, 150 );
        rightEye.setFillColor( Color(0, 0, 255));
        window.draw( rightEye );

        RectangleShape mouth;
        mouth.setSize( Vector2f( 300, 30 ) );
        mouth.setPosition( 175, 450 );
        mouth.setFillColor( Color(0, 0, 255));
        window.draw( mouth );

        RectangleShape nose;
        nose.setSize( Vector2f( 50, 50 ) );
        nose.setPosition( 292, 300 );
        nose.setFillColor( Color(0, 0, 255));
        window.draw( nose );
        //  END  DRAWING HERE
        /////////////////////////////////////


        // display the current contents of the window
        window.display();

        /////////////////////////////////////
        // BEGIN EVENT HANDLING HERE
        // check if any events happened since the last time checked
        while( window.pollEvent(event) ) {
            // if event type corresponds to pressing window X
            if(event.type == Event::Closed) {
                // tell the window to close
                window.close();
            }
            // check addition event types to handle additional events
        }
        //  END  EVENT HANDLING HERE
        /////////////////////////////////////
    }

    return 0;
}