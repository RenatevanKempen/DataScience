{
 "cells": [
  {
   "cell_type": "code",
   "execution_count": null,
   "metadata": {},
   "outputs": [],
   "source": [
    "from shapes import Triangle, Rectangle, Oval,  Paper \n",
    "rect1 = Rectangle()\n",
    "rect1.set_width(200)\n",
    "rect1.set_height(100)\n",
    "rect1.set_color(\"blue\")\n",
    "rect1.draw()\n",
    "\n",
    "rect2 = Rectangle()\n",
    "rect2.set_width(50)\n",
    "rect2.set_height(150)\n",
    "rect2.set_color(\"yellow\")\n",
    "rect2.set_x(100)\n",
    "rect2.set_y(100)\n",
    "rect2.draw()\n",
    "\n",
    "oval = Oval()\n",
    "oval.set_color('green')\n",
    "oval.randomize()\n",
    "oval.draw\n",
    "\n",
    "tri = Triangle(5, 5, 100, 5, 100, 200)\n",
    "tri.draw()\n",
    "\n",
    "Paper.display()"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": null,
   "metadata": {},
   "outputs": [],
   "source": []
  }
 ],
 "metadata": {
  "kernelspec": {
   "display_name": "Python 3",
   "language": "python",
   "name": "python3"
  },
  "language_info": {
   "codemirror_mode": {
    "name": "ipython",
    "version": 3
   },
   "file_extension": ".py",
   "mimetype": "text/x-python",
   "name": "python",
   "nbconvert_exporter": "python",
   "pygments_lexer": "ipython3",
   "version": "3.7.3"
  }
 },
 "nbformat": 4,
 "nbformat_minor": 2
}
