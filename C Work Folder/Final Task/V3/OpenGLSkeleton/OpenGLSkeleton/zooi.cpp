//latter refrence use
//for (auto it = drawList.begin(); it != drawList.end(); /* nothing */) {
//	if (/* condition */) {
//		it = drawList.erase(it); // Erase returns the next iterator } else { ++it; // Increment the iterator } }
//

    //glBegin(GL_POINTS);             // Start a new drawing block for drawing points
    //    // Draw points here
    //    // The point (0,0) corresponds to the lower left corner.

    //    // The following lines will draw the point (100, 200) in red
    //    glColor3f(1.0, 0.0, 0.0);   // Set color
    //    glVertex2f(100, 200);       // Set position

    //    // The following lines will draw the point (200, 400) in blue
    //    // Alternative approach to the above:
    //    Color color = { 0.0f, 0.0f, 1.0f }; // A color (see drawtools.h)
    //    glColor3fv(color.data());           // Set color from array
    //    PointF point = { 200, 400 };        // A two dimensional point (see drawtools.h)
    //    glVertex2fv(point.data());          // Set position from array
    //glEnd(); // End of the drawing block
	

//glutTimerFunc(1500, alarm, 1);
    //glutTimerFunc(2000, alarm, 2);

    // Set the background color.
    // The color is in the (red, green, blue, alpha) format (RGBA)
    // Color values range from 0.0f to 1.0f.

	// The following funtions setup the view of the screen.
    // OpenGL actually creates a 3D world, which is displayed trough a
    // viewport (the glut window). The way pixels are projected onto
    // this viewport is setup here.




	//PointF position = { 512, 384 };
	//Color color = { 0.2f, 1, 0.2f };
	//Pixel* pixel = new Pixel{ position, color };
	//drawList.push_back(pixel);
	//pixel->draw();

	//PointF begin1 = { 30,400 };
	//PointF begin2 = { 34, 430 };
	//PointF begin3 = { 45,410 };
	//PointF begin4 = { 48, 412 };
	//float lind = 2.0;
	////Line* line = new Line{ begin1, begin2, color ,lind };
	////drawList.push_back(line);
	//float r = 10;
	//int seg = 10;
	////Circle* cirle = new Circle(begin1, color, r, seg);
	////drawList.push_back(cirle);
	//Sqaure* sq = new Sqaure(begin1, begin2,begin3,begin4, color);
	//drawList.push_back(sq);
	//float speed = 200;
	//int health = 100;
	//Enemy* en = new Enemy(begin1, speed, health );
	//PointF posEnemy = en->Move();
	//Circle* cirle = new Circle(posEnemy, color, r, seg);
	//drawList.pufloat speed2 = 0;sh_back(cirle);
	//PointF bullet = { posEnemy.x()	,posEnemy.y() };
	//Line* bulletline = new Line{ bullet, begin2, color, lind };
	//drawList.push_back(bulletline);
	//glLineStipple(110,1400);	






	////PointF position = { 512, 384 };
//Color color = { 0.2f, 1, 0.2f };
////Pixel* pixel = new Pixel{ position, color };
////drawList.push_back(pixel);
////pixel->draw();
//float speed2 = 10;
//PointF begin1 = { (30 + speed2),(20 + speed2) };
//PointF begin2 = { 34, 430 };
////PointF begin3 = { 45,410 };
////PointF begin4 = { 48, 412 };
//float lind = 2.0;
//////Line* line = new Line{ begin1, begin2, color ,lind };
//////drawList.push_back(line);
//float r = 10;
//int seg = 10;
//////Circle* cirle = new Circle(begin1, color, r, seg);
//////drawList.push_back(cirle);
//
////
////Sqaure* sq = new Sqaure(begin1, begin2, begin3, begin4, color);
////drawList.push_back(sq);
//float speed = 200;
//int health = 100;
//
////amke neew enemy and put them in the back of the enemy list
//Enemy* en = new Enemy(begin1, begin1, speed, health);
//enenemyvector.push_back(en);
//
////enemylist.push_back(en);
////enemylist._Nextnode()->_Next
//////get the front enemey
//////Enemy* enemy = enemylist.front()->Move();
//////increment the movemment of the enemy
//PointF posEnemy = enenemyvector.front()->Move();
////posEnemy = { posEnemy[0] + 50, posEnemy[1] + 50 };
////enenemyvector.at(0)->Move();
////enemylist.;
////draw the ennemy
//enenemyvector.at(0)->Update(posEnemy);
//Circle* cirle = new Circle(posEnemy, color, r, seg);
//drawList.push_back(cirle);
////PointF bullet = { posEnemy.x()	,posEnemy.y() };
//Line* bulletline = new Line{ posEnemy, begin2, color, lind };
//drawList.push_back(bulletline);
////begin1 = { posEnemy[0]	,posEnemy.y() };
////Enemy* en = new Enemy(begin1, speed, health);
////enemylist.clear();
//
////cal the display function -> draw everything 
//glutPostRedisplay();
////cal this function agains
//glutTimerFunc(160, idle, 100);