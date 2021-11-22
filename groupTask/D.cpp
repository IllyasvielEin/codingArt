//
// Created by Illyasviel on 2021/10/4.
//
#include <bits/stdc++.h>
using namespace std;

class unit {
protected:
    int health;
public:
    unit() = default;

    explicit unit(int h) : health(h) {};
};

class enemy : public unit {
private:
    int needAttack;
    int type;
public:
    bool operator<(enemy e2) const {
        return getCost() <= e2.getCost();
    }

    bool operator>(enemy e2) const {
        return getCost() >= e2.getCost();
    }

    bool operator==(enemy e2) const {
        return health == e2.health && needAttack == e2.needAttack && type == e2.type;
    }

    enemy() = default;

    explicit enemy(int h, int n, int t) : unit(h), needAttack(n), type(t) {};

    int getHealth() const {
        return health;
    }

    int getNeedAtt() const {
        return needAttack;
    }

    int getCost() const {
        return health-needAttack;
    }

    void show() {
        printf("%d %d %d\n", health, needAttack, type);
    }
};

class bloodDevil : public unit {
public:
    explicit bloodDevil(int h) : unit(h){};

    int getHealth() const {
        return health;
    }
};

int main() {
    int enemyCount, bdHealth, enemyType;
    cin >> enemyCount >> bdHealth >> enemyType;
    bloodDevil hero(bdHealth);
    set<enemy> attackTo;
    int lastType = -1;
    int max;
    enemy tmpEne{};
    for (int i = 0; i < enemyCount; ++i) {
        int enemyHealth, needAttack, type;
        cin >> enemyHealth >> needAttack >> type;
        auto tmp = enemy(enemyHealth, needAttack, type);
        if ( lastType == -1 ) {
            lastType = type;
            tmpEne = tmp;
            max = tmp.getCost();
        }
        else {
            if ( lastType != type ) {
                attackTo.insert(tmpEne);
                lastType = type;
                tmpEne = tmp;
                max = tmp.getCost();
            }
            else if ( tmp.getCost() > max ) {
                tmpEne = tmp;
                max = tmp.getCost();
            }
            else if ( tmp.getCost() == max ) {
                if ( tmp.getHealth() > tmpEne.getHealth() ) {
                    tmpEne = tmp;
                }
            }
        }
    }
    attackTo.insert(tmpEne);

    bool flag = true;
    max = -1;
    int sto = -1;
    for (auto j : attackTo) {
        if ( j.getNeedAtt() > hero.getHealth() ) {
            flag = false;
            break;
        }
        if ( max == -1 ) {
            max = j.getNeedAtt();
            sto = j.getHealth();
        } else {
            if ( j.getNeedAtt() > max ) {
                max = j.getNeedAtt();
            }
            if ( j.getHealth() < sto ) {
                sto = j.getHealth();
            }
        }
    }
    if ( !flag ) {
        printf("-1");
    } else {
        printf("%d", hero.getHealth()-max+sto);
    }
    return 0;
}

