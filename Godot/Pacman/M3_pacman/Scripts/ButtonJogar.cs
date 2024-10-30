using Godot;
using System;

public partial class ButtonJogar : Button
{
	public void Jogar () {
		GetTree().ChangeSceneToFile("res://Cenas/mapa_1.tscn");
	}
}
