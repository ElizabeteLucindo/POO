using Godot;
using System;

public partial class pilula : Area2D
{
	public void Consumida(Node2D body) {
		jogador j;
		if (body is jogador) {
			j = (jogador)body;
			j.Pilula();
		
			QueueFree();
		}
		
		
		
	}
}
