void tr_xor(ll *cnt) {
	for(int len = 1, bit = 0; len < (1 << m); len *= 2, bit++) {
		for(int st = 0; st < (1 << m); st += 2*len) {
			for(int i = 0; i < len; i++) {
				ll a = cnt[st + i], b = cnt[st + i + len];
				if(bit % 3 == 0) {
					cnt[st + i] = a + b;
					cnt[st + i + len] = a - b;
				}
				else if(bit % 3 == 1) {
					cnt[st + i] = a + b;
					cnt[st + i + len] = b;
				}
				else if(bit % 3 == 2) {
					cnt[st + i] = a;
					cnt[st + i + len] = a + b;
				}
			}
		}
	}
}

void itr_xor(ll *cnt) {
	for(int len = 1, bit = 0; len < (1 << m); len *= 2, bit++) {
		for(int st = 0; st < (1 << m); st += 2*len) {
			for(int i = 0; i < len; i++) {
				ll a = cnt[st + i], b = cnt[st + i + len];
				if(bit % 3 == 0) {
					cnt[st + i] = (a + b) / 2;
					cnt[st + i + len] = (a - b) / 2;
				}
				else if(bit % 3 == 1) {
					cnt[st + i] = a - b;
					cnt[st + i + len] = b;
				}
				else if(bit % 3 == 2) {
					cnt[st + i] = a;
					cnt[st + i + len] = b - a;
				}
			}
		}
	}
}
