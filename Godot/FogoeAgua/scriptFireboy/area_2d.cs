using Godot;
using System;

public partial class area_2d : Area2D
{
	public void EntrouArea(Node2D body) {
		jogadorFireboy j;
		if (body is jogadorFireboy) {
			j = (jogadorFireboy)body;
			GD.Print("Morte");
			j.Morte();
		}
	}
}
